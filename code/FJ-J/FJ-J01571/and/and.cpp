#include<bits/stdc++.h>
using namespace std;
int a,b,c[200010],ans,g[200010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	sort(c+1,a+c+1,cmp);
	if(b==1){
		cout<<c[1];
		return 0;
	}
	if(b==2){
		int e=c[1];
		bool flag=0;
		for(int i=1;i<=20;i++){
			if(e%2==1){
				break;
			}
			else{
				e%=2;
			}
			if(e==1){
				flag=1;
			}
		}
		if(flag==1) cout<<(c[2]&c[3]);
		else{
			cout<<(c[1]&c[2]);
		}
		return 0;
	}
	if(b==3){
		cout<<max((c[1]&c[2])&c[3],(c[1]&c[3])&c[2]);
		return 0;
	}
	if(c[1]>=4){
		if(c[1]==pow(2,b)) cout<<c[b];
		else cout<<a-b;
		return 0;
	}
	if(c[1]<4){
		cout<<c[b];
		return 0;
	}
	if(b==2){
		for(int i=1;i<=a;i++){
			g[i]=(c[i]&c[i+1]);
		}
		sort(g+1,g+a+1,cmp);
		cout<<g[1];
		return 0;
	}
	if(b==a){
		
	}
	return 0;
}
