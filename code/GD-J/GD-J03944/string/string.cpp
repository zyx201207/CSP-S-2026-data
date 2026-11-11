
#include<bits/stdc++.h> 
using namespace std;
struct s{
	long long g;
	string s;
};
	s a[200005];
	string s1,s2;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long cnt =0,cnt1 =0;
	for(int i = 1;i<=n;i++){
		cin>>a[i].g>>a[i].s;
		cnt+=a[i].g;
	}for(int i = 1;i<=n;i++){
		for(int j = 1;j<=a[i].g;j++){
			s1+=a[i].s;
		}
	}s2 =s1;
	reverse(&s2[0],&s2[cnt]);cout<<s1<<endl<<s2<<endl;
	if(s2 == s1){
		cout<<'0'<<endl;return 0;
	}
	for(int i = 0;i<=cnt/2-1;i++){
		if(s1[i]!=s2[i])cnt1++;
	}cout<<cnt1;
	

}/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b*/

