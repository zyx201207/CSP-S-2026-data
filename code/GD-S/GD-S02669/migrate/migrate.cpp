#include<bits/stdc++.h>
//#include<windows.h>//别忘了删 
using namespace std;
const int N=1e6+10;
int n,d;
int a[N];
bool ck(int x,int y){
	int l=x;
	while(1){
		if(a[l+1]-a[x]<=d){
			l++;
		}else break;
	}
	if(l+d>y&&l<y){
		//printf("%d.%d.%d\n",x,y,l);
		return 1;
	}
	else return 0;
}
void S(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(ck(i,j)){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	//该代码由人类书写，请注意甄别 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int _=1,c=0;
	cin>>c>>_;
	while(_--)S();
	return 0;
}

