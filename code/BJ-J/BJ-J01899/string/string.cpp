#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long cnt,n;
struct num{
	long long val;
	char s;
}a[N];
void compare(string s1,string s2){
	if(s1==s2){
		return;
	}
	else{
		cnt++;
		int t1=s1.size();
		for(int i=0;i<t1;i++){
			if(s1[i]!=s2[i]){
				s1[i]=s2[i];
				s2[s1.size()-i-1]=s1[i];
				compare(s1,s2);
			}
			else{
				continue;
			}
		}
		return;
	}
}
string s2;
string s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].val;
		cin>>a[i].s;
		for(int j=1;j<=a[i].val;j++){
			s1+=a[i].s;
			cout<<s1<<' ';
		}
		if((a[i].s!=a[i-1].s)&&i!=1){
			flag=1;
		}
	}
	if(flag==0){
		cout<<0;
		return 0;
	}
	int t=s1.size();
	for(int i=t-1;i>=0;i--){
		s2[t-i-1]=s1[i];
	}
	compare(s1,s2);
	cout<<cnt;
	return 0;
}
