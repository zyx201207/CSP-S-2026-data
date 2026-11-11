#include<bits/stdc++.h>
using namespace	std;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,cnt=0,res=0,ans=0;
	string ss,s1,c,cc;
//	bool f=false;
	cin>>n;
	while(n--){
		int a;
		string s;
		cin>>a>>s;
		for(int i=1;i<=a;i++){
			ss+=s;
		}
		//ans+=a;
	}	
	for(int i=ss.size()-1;i>=0;i--){
		s1+=ss[i];
	}
//	if(ans%2==0){
//		cnt=ans/2;
//		f=true;
//	}else{
//		cnt=ans/2;
//		f=false;
//	}
//	if(f==true){
//		for(int i=0;i<cnt;i++){
//			c+=ss[i];
//		}
//		for(int i=cnt;i<ss.size();i++){
//			cc+=ss[i];
//		}
//	}
//	if(c==cc){
//		cout<<0;
//		return 0;
//	}
//		for(int i=0;i<=c.size();i++){
//		if(c[i]!=cc[i]) res++;
//	}
	if(s1==ss){
		 cout<<0;
		 return 0;
	}
	for(int i=0;i<=ss.size();i++){
		if(s1[i]!=ss[i]) cnt++;
	}
	cout<<cnt/2;
//cout<<res;

	return 0;
}
/*
3
2 a
2 b
1 c        aa bbc cb baa
		   aabaa aabaa
		   aabb bbaa
2
2 a
3 a


6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
