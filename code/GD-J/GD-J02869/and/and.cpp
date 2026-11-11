#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
string d2b(int a){
	string t="",res="";
	while(a!=0){
		int p=a%2;
		t+=char(p+'0');
		a/=2;
	}
	for(int i=t.size()-1;i>=0;i--){
		res+=t[i];
	}
	return res;
}
int And(int a,int b){
	string b1=d2b(a),b2=d2b(b),res;
	for(int i=0;i<min(b1.size(),b2.size());i++){
		int t1=b1[i]-'0',t2=b2[i]-'0';
		res=char('0'+(t1&&t2))+res;
	}
	int x=1,ans=0;
	for(int i=0;i<res.size();i++){
		ans+=(res[res.size()-1-i]-'0')*x;
		x*=2;
	}
	return ans;
}
int test(int lvl,int bg,int lst=2147483647){
	int ans=And(a[bg],lst);
	if(lvl!=m-1){
		for(int i=bg+1;i<n;i++){
			ans=max(ans,test(lvl+1,i,ans));
		}
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=0;i<n-m;i++){
		ans=max(ans,test(0,i));
	}
	cout<<ans;
} 
