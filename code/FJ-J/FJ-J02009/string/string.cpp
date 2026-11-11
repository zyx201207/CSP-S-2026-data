#include<iostream>
#include<cstdio>
using namespace std;
int n,a,b[200005][27],l[200005];
long long ans;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	if(n==1){
		cout<<0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		cin>>c;
		l[i]=c-'a';
		b[i][l[i]]=a;
	}
	for(int i=1;i<n;){
		if(l[i]!=l[n]){
			ans+=min(b[i][l[i]],b[n][l[n]]);	
		}if(b[i][l[i]]>b[n][l[n]]){
			b[i][l[i]]-=b[n][l[n]];
			n--;
		}else if(b[i][l[i]]==b[n][l[n]]){
			n--;
			i++;
		}else{
			b[n][l[n]]-=b[i][l[i]];
			i++;
		}
	}
	cout<<ans;
}
