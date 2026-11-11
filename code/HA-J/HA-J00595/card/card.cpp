#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,s;
	cin>>a>>s;
	vector<char> a1(a+10);
	for(int i=1;i<=a;i++){
		cin>>a1[i];
	}
	vector<int> a2(s+10);
	int s1=a;
	while(a--){
		string a3;
		for(int i=s1-a;i<=s1;i++){
			if(a3.find(a1[i])!=-1){
				int x=a3.find(a1[i]);
				a3=a3.substr(0,x+1);
				continue;
			}
			a3+=a1[i];
		}
		for(int i=1;i<=s;i++){
			if(a3.find(a1[i])!=-1) a2[i]++;
		}
	}
	for(int i=1;i<=s;i++){
		cout<<a2[i]<<" ";
	}
	return 0;
}
