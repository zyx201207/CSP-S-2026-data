#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,ans,it=1;
long long num1[N],num2[N];
char x,y;
string c,s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		long long a;
		y=x;
		cin>>a>>x;
		c+=x;
		if(i>0&&x!=y) it++;
		num1[it]+=a;
	}
	for(int i=1;i<=it;i++) num2[i]=num1[it-i+1];
//	for(int i=1;i<=it;i++) cout<<num1[i]<<" ";
	int l=c.size();
	for(int i=0;i<l;i++)
		if(c[i]!=c[i-1])
			s1+=c[i];
	l=s1.size();
	for(int i=0;i<l;i++) s2+=s1[l-i-1];
	int mid=ceil(l/2);
	for(int i=0;i<mid;i++){
		if(s1[i]!=s2[i]) ans+=num1[i+1];
		else if(num1[i+1]!=num2[i+1]) ans+=abs(num1[i+1]-num2[i+1]);
	}
	cout<<ans;
	return 0;
}
