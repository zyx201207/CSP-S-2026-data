#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long num;
	string c;
	long long b;
}a[200005];
bool cmp(Node x,Node y){
	return x.b>y.b;
}
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	long long n,m;cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i].num;
		a[i].b=0;
		string s="";
		while(a[i].num>0){
			if(a[i].num%2==1)s+='1';
			else s+='0';
			if(a[i].num%2==1)a[i].b++;//保存1的个数 
			a[i].num/=2;
		}
		long long len=s.size();
		for(long long j=0;j<s.size();j++){
			a[i].c+=s[len-j-1];
		}
	}
	sort(a+1,a+n+1,cmp);
	string t=a[1].c;
	cout<<t<<endl;
	for(long long i=2;i<=m;i++){
		long long maxx=max(t.size(),a[i].c.size()),minn=min(t.size(),a[i].c.size());
		cout<<maxx<<endl;
		for(long long j=0;j<maxx;j++){
			if(j<=minn)
				if(t[j]==a[i].c[j]==1)t[j]=1;
				else t[j]=0;
		}
	}
	int sum=0;
	for(long long i=0;i<t.size();i++){
		if(t[i]==1){
			sum+=pow(2,i);
		}
	}
	cout<<sum;
	return 0;
}
