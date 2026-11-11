#include <bits/stdc++.h>
using namespace std;
int a[200010];
char b[200010];
bool P(string s){
	string s1=s;
	reverse(s1.begin(),s1.end());
	if(s1==s) return true;
	else return false;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,t_s1,t_s2;
	int n;
	long long sum1=0,sum2=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	t_s1=s;
	t_s2=s;
	if(P(s)){
		cout<<0;
		return 0;
	}
	if(s.size()%2==0){
		for(int i=0;i<(t_s1.size()/2);i++){
			if(t_s1[i]!=t_s1[t_s1.size()-i-1]){
				t_s1[i]=t_s1[t_s1.size()-i-1];
				sum1++;
			}
		}
		for(int i=t_s2.size()-1;i>=(t_s2.size()/2);i--){
			if(t_s2[i]!=t_s2[t_s2.size()-i-1]){
				t_s2[i]=t_s2[t_s2.size()-i-1];
				sum2++;
			}
		}
	}
	else if(s.size()%2==1){
		for(int i=0;i<=(t_s1.size()/2)-1;i++){
			if(t_s1[i]!=s[t_s1.size()-i-1]){
				t_s1[i]=s[t_s1.size()-i-1];
				sum1++;
			}
		}
		for(int i=t_s2.size()-1;i>=(t_s2.size()/2)+1;i--){
			if(t_s2[i]!=t_s2[t_s2.size()-i-1]){
				t_s2[i]=t_s2[t_s2.size()-i-1];
				sum2++;
			}
		}
	}
	cout<<min(sum1,sum2);
	return 0;
} 
