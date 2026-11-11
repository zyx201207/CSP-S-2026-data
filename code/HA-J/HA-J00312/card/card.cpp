#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,sum[500005];
string num[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>sum[i];
	}
	for(int i=1;i<=n;i++){
		string s="";
		for(int j=i;j<=n;j++){
			int t=sum[j];
			string s1="";
			while(t>0){
				s1+=t%10+'0';
				t/=10;
			}
			reverse(s1.begin(),s1.end());
			if(s.find(s1)==string::npos){
				s+=s1;
			}else{
				s.erase(s.find(s1)+1,s.size()-s.find(s1)-1);
			}
		}
		cout<<s<<endl;
		num[i]=s;
	}
	for(int i=1;i<=m;i++){
		int res=0;
		string s1="";
		int t=i;
		while(t>0){
			s1+=t%10+'0';
			t/=10;
		}
		for(int j=1;j<=n;j++){
			if(num[j].find(s1)!=string::npos){
				res++;
			}
		}
		cout<<res<<" ";
	}
	return 0;
}

