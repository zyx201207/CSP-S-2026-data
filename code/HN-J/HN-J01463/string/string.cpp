#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a[200005][2],n;
	long long cnt=0,cnt2=0,cnt3=0,cnt4=0;
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i][0];
		char b;
		cin>>b;
		a[i][1]=b-'a';
		cnt+=a[i][0];
	}
	//cout<<cnt<<endl;
	int i=0;
	int j=n-1;
	cnt2+=a[i][0];
	cnt3+=a[j][0];
	if(cnt2<cnt3 &&a[i][1]!=a[j][1]){
		cnt4+=cnt2;
	}
	if(cnt2>=cnt3 &&a[i][1]!=a[j][1]){
		cnt4+=cnt3;
	}
	while(i<j-1){//cout<<cnt2<<' '<<cnt3<<' '<<cnt4<<endl;
		if(cnt2<cnt3){
			if(a[i+1][1]!=a[j][1]){
				cnt4+=cnt3-cnt2;
			}
			i++;
			cnt2+=a[i][0];
		}
		if(cnt2>cnt3){
			if(a[i][1]!=a[j-1][1]){
				cnt4+=cnt2-cnt3;
			}
			j--;
			cnt3+=a[j][0];
		}
		else{
			if(a[i][1]!=a[j][1]){
				cnt4+=min(a[i][0],a[j][0]);
			}
			i++;
			cnt2+=a[i][0];
			j--;
			cnt3+=a[j][0];
		}
	}
	cout<<cnt4;
	return 0;
}
