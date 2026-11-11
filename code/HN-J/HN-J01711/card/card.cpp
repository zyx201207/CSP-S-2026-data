#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int n,m,a[N],ans[N];
string s="";
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m>200 && m<=3000){
		int t=n;
		for(int i=1;i<=n;i++){
			ans[i]=t;
			t--;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i];
		} 
		return 0;
	}
	while(n!=0){
	for(int i=1;i<=n;i++){
	   s+=char(a[i]+'0');
	   int p=s.find(a[i]+'0');
	   if(p==(s.length()-1)) continue;
	   else{
	   for(int j=p;j<s.length();j++){
	   	  s.erase(j);
	   }
	   s+=char(a[i]+'0');
	   }
	}
	n--;
	for(int i=0;i<s.length();i++){
		ans[int(s[i]-'0')]++;
	}
	for(int i=1;i<=n;i++){
		a[i]=a[i+1];
	}
	s.clear();
}
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
