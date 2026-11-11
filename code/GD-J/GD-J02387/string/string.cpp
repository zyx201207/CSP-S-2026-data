#include<bits/stdc++.h>
using namespace std;
int sh[200005],sh2[200005];
char zi[200005],zi2[200005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>sh[i]>>zi[i];
		sh2[n-i+1]=sh[i];
		zi2[n-i+1]=zi[i];
	}
	int cnt1=1,cnt2=1;
	long long cnt=0;
	while(cnt1<=n && cnt2<=n){
		if(zi[cnt1]==zi2[cnt2]){
			if(sh[cnt1]>sh2[cnt2]){
				sh[cnt1]-=sh2[cnt2];
				cnt2++;
			}else if(sh[cnt1]<sh2[cnt2]){
				sh2[cnt2]-=sh[cnt1];
				cnt1++;
			}else{
				cnt1++;
				cnt2++;
			}
		}else{
			if(sh[cnt1]>sh2[cnt2]){
				sh[cnt1]-=sh2[cnt2];
				cnt+=sh2[cnt2];
				cnt2++;
			}else if(sh[cnt1]<sh2[cnt2]){
				sh2[cnt2]-=sh[cnt1];
				cnt+=sh[cnt1];
				cnt1++;
			}else{
				cnt+=sh[cnt1];
				cnt1++;
				cnt2++;
			}
		}
	}
	cout<<cnt/2;
	return 0;
}
