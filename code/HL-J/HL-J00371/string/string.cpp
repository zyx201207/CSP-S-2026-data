#include<bits/stdc++.h>
using namespace std;

string s,rev;
int len;

void in(int num,char c){
	for(int i=1;i<=num;i++)
		s+=c;
		
	return;
}

int xg(){
	int ans=0;
	
	for(int i=0;i<len;i++)
		for(int j=0;j<len;j++)
			if(s[i]!=rev[i]){
				ans++;
				
				s[i]=rev[i];
				rev=s;
				reverse(rev.begin(),rev.end());
			}
	return ans;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	
	cin>>n;
	for(int i=1;i<=n;i++){
		int num;
		char c;
		
		cin>>num>>c;
		in(num,c);
	}
	
	len=s.size();
	rev=s;
	reverse(rev.begin(),rev.end());
	
	cout<<xg()<<endl;
	
	return 0;
}

