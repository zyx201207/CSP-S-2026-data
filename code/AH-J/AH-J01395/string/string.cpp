#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
string str,str1,str2,st;
ll len;
//struct node{
//	char ch;
//	ll id;
//}a[MAXN];
//ll len,mid;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//    int n;
//    cin>>n;
//    for(int i=1;i<=n;i++){
//    	cin>>a[i].id>>a[i].ch;
//    	len+=a[i].id;
//	}
//    if(len%2==0){
//    	mid=len/2;
//    	
//	} 
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		ll x;
		cin>>x;
		cin>>st;
		for(int j=1;j<=x;j++){
			str+=st; 
		}
//		cout<<str<<"\n";
		len+=x;
	}
//	cout<<str<<"\n";
//	cout<<len<<"\n";
	int len1;
	if(len%2==0){
		len1=len/2;
		for(int i=0;i<len1;i++){
			str1+=str[i];
		}
		for(int i=len1;i<len;i++){
			str2+=str[i];
		}
	}else{
		len1=len/2;
		for(int i=0;i<len1;i++){
			str1+=str[i];
		}
		for(int i=len1+1;i<len;i++){
			str2+=str[i];
		}
	}
//	cout<<"len1="<<len1<<"\n"; 
//	cout<<str1<<"\n"<<str2<<"\n";
	int ans=0;
	for(int i=0;i<len1;i++){
		if(str1[i]!=str2[i]){
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0; 
} 
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
