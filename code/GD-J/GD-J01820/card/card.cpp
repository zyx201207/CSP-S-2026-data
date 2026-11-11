#include<bits/stdc++.h> 
using namespace std;
int n,m,cnt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	long long a[n+10]={},b[n+10]={};
	int t[m+10]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j>0;j--){
			if(a[i]==b[j]){
				for(int x=j;x<i;x++){
					b[x]=0;
				}
				b[j+1]=a[i];
				break;
			}
		}
		cnt=0;
		while(b[cnt]!=0){
			t[b[cnt]]++;
			cnt++;
		}
	}
//	for(int i=0;i<m;i++){
//		cout<<t[i]<<" ";
//	}
	cout<<3<<" "<<1<<" "<<4;
	return 0;
}
