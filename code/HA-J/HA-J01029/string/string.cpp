#include<bits/stdc++.h>
using namespace std;
int t[1005],b[200005];
char d[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	long long n,a,mx=-1,cnt=0;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		b[i]=a;
		d[i]=c;
		mx=max(mx,a);
		t[int(c)]=a;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=int('a');i<=int('z');i++){
		if(t[i])cnt++;
	}
	if(cnt==1){
		cout<<0;
		return 0;
	}
	if(n*mx<pow(10,8)){//56pts
		int dif=0;
		for(int p=1;p<=n;p++){
			for(int j=1;j<=b[p];j++){
				s+=d[p];
			}
		}
		string ss=s;
		for(int i=0;i<s.size();i++){
			ss[i]=s[s.size()-i-1];
		}//cout<<s<<endl<<ss;
		for(int i=0;i<s.size();i++){
			if(s[i]!=ss[i])dif++;
		}
		printf("%d",dif/2);
		return 0;
	}
	return 0;
}
/*
3
2 a
2 b
1 c
2
2 a
3 a

*/
