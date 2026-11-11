#include<iostream>
using namespace std;
int a[500005],s[500005],a1[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		a1[i]=a[i];
		for(int j=1;j<i;j++){
			if(a1[i]==a1[j]){
				for(int t=j;t<=n;t++){
					a1[t]=0;
				}
			}
		}
		for(int j=1;j<=n;j++){
			s[a1[j]]++;
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

