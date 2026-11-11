#include<bits/stdc++.h>
using namespace std;
int a[50003];
bool b[50003];
int total[50003];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int t=i;t<j;t++){
				if((!b[j])&&(!b[t])&&a[j]==a[t]){
					//cout<<j<<" "<<t<<endl;
					while(t<j){
						b[t]=true;
						t++;
					}
				}
			}
		}
		for(int j=i;j<n;j++){
			if(!b[j]){
				total[a[j]]++;
				//cout<<a[j]<<" ";
			}
		}
		memset(b,0,sizeof(b));
	}
	for(int i=1;i<=m;i++) cout<<total[i]<<" ";
	return 0;
}
