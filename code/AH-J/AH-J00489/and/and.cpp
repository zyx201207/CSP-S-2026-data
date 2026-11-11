#include <bits/stdc++.h>
using namespace std;
long long n,m,sum=1;
long long pow_two[63];
string ans;
struct Node{
	long long q;
	long long les; 
}a[500005];
bool cmp(Node x,Node y){
	if(x.les==y.les){
		return x.q>y.q;
	}else{
		return x.les>y.les;
	}
}
string ten_to_two(long long x){
	string s="",s1="";
	while(x!=0){
		s1+=char((x%2)+'0');
		x/=2;
	}
	for(int i=0;i<int(s1.length());i++){
		s+=s1[s1.length()-i-1];
	}
	return s;
}
long long two_to_ten(string s){
	long long tmp=0;
	string s1;
	for(int i=0;i<int(s.length());i++){
		s1+=s[s.length()-i-1];
	}
	for(int i=0;i<int(s1.length());i++){
		tmp+=(s1[i]-'0')*pow_two[i];
	}
	return tmp;
}
string chang(string s1,string s2){
	for(int i=0;i<int(max(s1.length(),s2.length()));i++){
		if(s1[i]==s2[i]&&s1[i]=='1'){
			s1[i]='1';
		}else{
			s1[i]='0';
		}
	}
	return s1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=0;i<=31;i++){
		pow_two[i]=sum;
		sum*=2;
	}
//	for(int i=0;i<=31;i++) cout<<pow_two[i]<<' ';
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].q;
		for(int j=1;j<=31;j++){
			if(a[i].q<pow_two[j]){
				a[i].les=a[i].q-pow_two[j-1];
				break;
			}
		}
	}
	sort(a+1,a+1+n,cmp);
//	for(int i=1;i<=n;i++) cout<<a[i].q<<' '<<a[i].les<<endl;
	ans=ten_to_two(a[1].q);
	for(int i=2;i<=m;i++){
		ans=chang(ten_to_two(a[i].q),ans);
	}
	cout<<two_to_ten(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
