#include<bits/stdc++.h>
using namespace std;
int n,m,a[800000],b[800000],s[800000];
bool c[800000];
int temp[800000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		if(temp[a[i]]>0){
			b[i]=temp[a[i]];
			temp[a[i]]=i;
		}else{
			temp[a[i]]=i;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(c[a[j]]==1){
				for(int t=b[j];t<j;t++){
					c[a[t]]=0;
				}
				c[a[j]]=1;
			}else{
				c[a[j]]=1;
			}
		}
		for(int j=i;j<n;j++){
			if(c[a[j]]){
				s[a[j]]++;
				c[a[j]]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}

