#include<bits/stdc++.h>
using namespace std;
char a[200005];
int b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int top=0;
	int n,x,ans=0;
	char y;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		cin>>y;
		if(a[top]!=y){
			top++;
			a[top]=y;
			b[top]=x;
		}
		else{
			b[top]+=x;
		}
	}
	if(top>0){
		for(int i=1,j=top;i<=top;i++,j--){
			if(a[i]!=a[j]&&i<j){
				ans+=b[j];
			}
		}
		cout<<ans;
	}
	else{
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
