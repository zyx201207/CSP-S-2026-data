#include<bits/stdc++.h>
using namespace std;

int  s1[50005],t[100];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	std::stack <int> s[50005];
	int a,b,m=1;
	for(int i=1;i<=a;i++){
	cin>>s1[i];	
	}
	
	for(int x=1;x<=a;x++){
		for(int i=m;i<=a;i++){
			if(s.find(s1[i])>s.size()){
				s.push(s1[i]);
			}else{
				int n=s.find(s1[i]);
				for(int j=s.size();j>=n;j--){
				s.pop();
				s.push(s1[i]);
				}
			}
		}
		for(int i=1;i<=s.size();i++){
			t[s[i]]++;
		}
		m++;
	}
	for(int i=1;i<=9;i++){
		cout<<t[i]<<' ';
	}
	return 0;
}
