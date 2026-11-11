#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n+1],b[n+1],cnt[n+1],s[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[n+1]={0},cnt[n+1]=0;
		for(int j=i;j<=n;j++){
		    cnt[a[j]]++;
		    if(cnt[a[j]]>1){
		    	for(int k=1;k<=n;k++){
		    		if(a[k]==a[j]){
		    			for(int x=k;k<=n;k++){
		    				b[x]=0;
						}
						break;
					}
				}
				cnt[a[j]]=1;
			}
			b[j]=a[j];
		}
		for(int j=1;j<=n;j++){
		    if(b[j]!=0){
		    	s[b[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
