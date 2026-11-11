#include<bits/stdc++.h>
using namespace std;
#define int long long
struct w{
	int k;
	char c;
}q[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int d;
	cin>>d;
	for(int i=1;i<=d;i++){
		int k;//ÊýÁ¿ 
		char c;//×Ö·û 
		cin>>k;
		cin>>c;
		w ls;
		ls.c=c;
		ls.k=k;
		q[i]=ls;
	}
	int l=1,r=d;
	int s1=q[1].k;
	int s2=q[d].k;
	int ans=0;
	while(l<r){
		if(s1==0){
			l++;
			s1=q[l].k;
			continue;
		}
		if(s2==0){
			r--;
			s2=q[r].k;
			continue;
		}
		if(q[l].c==q[r].c){
			if(s1<s2){
				s2-=s1;
				s1=0;
			}else{
				s1-=s2;
				s2=0;
			}
		}else{
			if(s1<s2){
				s2-=s1;
				ans+=s1;
				s1=0;
			}else{
				s1-=s2;
				ans+=s2;
				s2=0;
			}
		}
	}
	cout<<ans;
	return 0;
} 
