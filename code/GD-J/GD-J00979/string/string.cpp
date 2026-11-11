#include<bits/stdc++.h>
using namespace std;
long long n,a,ans1=0,ans2=0;
char c;
string s,su1,su2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a;
		cin>>c;
		for (int j=1;j<=a;j++){
			s+=c;
		}
	}
	su1=s;
	su2=s;
	for (int i=0;i<s.size()/2;i++){
		if (su1[i]!=su1[s.size()-i-1]){
			su1[i]=su1[s.size()-i-1];
			ans1+=1;
		}
	}
	for (int i=0;i<s.size()/2;i++){
		if (su2[i]!=su2[s.size()-i-1]){
			su2[s.size()-i-1]=su2[i];
			ans2+=1;
		}
	}
	cout<<min(ans1,ans2);
	return 0;
}
