#include<bits/stdc++.h>
using namespace std;
long long a[200005],ans[200005];
int t[200005];
bool f[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	bool f1=0;
	for(int i=0;i<n;i++){
		memset(f,sizeof(f),0);
		memset(t,sizeof(t),0);
		f1=0;
        for(int j=i;j<n;j++){
        	if(f[a[j]]==0){
        		t[j]=a[j];
        		f[a[j]]=1;
        	}else{
        		for(int k=i;k<=j;k++){
        			if(f1){
        				f[t[k]]=0;
        				t[k]=0;
        			}
        			if(t[k]==a[j]){
        				f1=1;
        			}
        		}
        	}
        }
        for(int l=1;l<=n;l++){
        	if(f[l]==1) ans[l]++;
        }
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0; 
	/*奇葩人物志 我来了
	蚝煤树枝#2235 来击剑*/ 
}
