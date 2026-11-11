#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
struct App{
	ll num;
	char ch;
};
stack<App> w,v;
char c[N];
ll a[N];
ll ans;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		v.push({a[i],c[i]});
		w.push({a[n-i+1],c[n-i+1]});
	}
	while(!w.empty()){
		ll num1=w.top().num;
		ll num2=v.top().num;
		char ch1=w.top().ch;
		char ch2=v.top().ch;
//		cout<<num1<<' '<<ch1<<' '<<num2<<' '<<ch2<<' '<<'\n';
//        cout<<ch1<<" 1 "; 
		w.pop();
		v.pop();
		if(ch1!=ch2){
			ans+=min(num1,num2);
		}
		if(num1>num2){
			w.push({num1-num2,ch1});
		}else if(num2>num1){
			v.push({num2-num1,ch2});
		}
	}
	cout<<ans/2;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

3
2 a
2 b
1 c
*/
