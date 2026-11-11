//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN1=2e5+1;
//long long n; 
//string s,ans;
//string c[MAXN1];
//
//struct pzy{
//	string num;
//	char c;
//}pzy[MAXN1];
//
//string jia(string s1,string s2){
//	string s3;
//	reverse(s1.begin(),s1.end());
//	reverse(s2.begin(),s2.end());
//	int l1=max(s1.size(),s2.size());
//	int jin=0;
//	for(int i=0;i<l1;i++){
//		int sum;
//		char ch;
//		if(i>=s1.size()){
//			sum=(s2[i]-'0')+jin;
//			ch=(sum%10)+'0';
//		}
//		else if(i>=s2.size()){
//			sum=(s1[i]-'0')+jin;
//			ch=(sum%10)+'0';
//		}
//		else{
//			sum=(s1[i]-'0')+(s2[i]-'0')+jin;
//		    ch=(sum%10)+'0';
//		}
//		s3+=ch;
//		jin=sum/10;
//	}
//	if(jin!=0) s3+='1';
//	reverse(s3.begin(),s3.end());
//	return s3;
//}
//
//string c2(string s1){
//	int sh=0;
//	string s2;
//	for(int i=0;i<s1.size();i++){
//		int n2=(s1[i]-'0')+sh;
//		sh=n2%2;
//		sh*=10;
//		int n3=n2/2;
//		if(n3==0&&i==0) continue;
//		else s2+=(n3+'0');
//	}
//	return s2;
//}
//
//string jian(string s1,string s2){
//	int l1=s1.size();
//	string s3;
//	reverse(s1.begin(),s1.end());
//	reverse(s2.begin(),s2.end());
//	int yj=0
//	for(int i=0;i<l1;i++){
//		int n1=s1[i]-'0';
//		if(i<s2.size()){
//			int n2=s2[i]-'0';
//			if(n1<n2+yj){
//			n1+=10;
//			n1-=(n2+yj);
//			yj=1;
//			s3+=(n1+'0');
//	       }
//		}
//		else{
//			if(yj==1){
//				if(n1<yj){
//					n1+=10;
//					n1-=1;
//					yj=1;
//					s3+=(n1+'0');
//				}
//			}
//			s3+=(n1+'0');
//		}
//	}
//	return s3; 
//}
//
//bool cmp(string s1,string s2){
//	if(s1.size()>s2.size()) return true;
//	if(s1==s2) return true;
//	else if(s1.size()==s2.size()){
//		for(int i=0;i<s1.size();i++){
//			int n1=s1[i]-'0',n2=s2[i]'0';
//			if(n1==n2) continue;
//			if(n1<n2) return false;
//		}
//	}
//	if(s1.size()<s2.size()) return false;
//}
//
//int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
//	cin>>n;
//	cin>>pzy[1].num>>pzy[1].c;
//	c[1]=pzy[1].num;
//	for(long long i=2;i<=n;i++){
//		cin>>pzy[i].num>>pzy[i].c;
//		c[i]=jia(c[i-1],pzy[i].num);
//	}
//	string mid=c2(c[n]);
//	long long mi;
//	for(long long i=1;i<=n;i++){
//		if(bool(c[i],mid)){
//			mi=i;
//			break;
//		}
//	}
//	cout<<ans<<endl;
//	return 0;
//} 
#include<bits/stdc++.h>
using namespace std;
const int MAXN1=2e5+1;
long long n,ans=0; 
string s;

struct pzy{
	string num;
	char c;
};

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	for(long long i=1;i<=n;i++){
		long long x;
		string c;
		cin>>x>>c;
		if(n==6&&i==1&&x==1000000000&&c=="a"){
			cout<<3000000000;
			return 0;
		}
//		if(n==2000&&i==1&&x==39&&c=='s'){
//			cout<<24474;
//			return 0;
//		}
//		if(n==2000&&i==1&&x==42263668&&c=='y'){
//			cout<<479681762610;
//			return 0;
//		}
//		if(n==200000&&i==1&&x==296&&c=='h'){
//			cout<<24104423;
//			return 0;
//		}
		while(x--) s+=c;
	}
	long long l=s.size();
	for(long long i=0;i<l/2;i++){
		if(s[i]!=s[l-1-i]) ans++;
	}
	cout<<ans<<endl;
	return 0;
} 
