#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
string s;
string l;

bool panduan(string a){
	string q;
	reverse(a.begin(),a.end());
	q=a;
	reverse(a.begin(),a.end());
	if(q==a){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i = 0; i<n; i++){
		cin>>a[i]>>l[i];
	}
	for(int i = 0 ;i<n;i++){
		for(int j = 0;j<a[i];j++){
			s+=l[i];
		}
	}
	if(s.size()==1){
		cout<<0;
		return 0;
	}
	else if(s.size()==2){
		cout<<1;
		return 0;
	}
	for(int i = 1; i<s.size();i++){
		if(s[i]!=s[i-1]){
			break;
		}
		if(i==s.size()-1){
			cout<<0;
			return 0;
		}
	}
	string fanzhuan;
	reverse(s.begin(),s.end());
	fanzhuan=s;
	reverse(s.begin(),s.end());
	if(fanzhuan==s){
		cout<<0;
		return 0;
	}
//	if(panduan(s)){
//		cout<<0;
//		return 0;
//	}
	if(n==2 && a[0]==a[1]){
		cout<<a[0];
		return 0;
	}
	if(n==2){
		cout<<min(a[0],a[1]);
		return 0;
	}
	int num=s.size();
	string fuzhi=s;
	int j=1;
	for(int i = 0; i<s.size(); i++){
		if(fuzhi[num-1]==fuzhi[i]){
			num--;
			continue;
		}
		fuzhi[num-1]=fuzhi[i];
		if(panduan(fuzhi)){
			cout<<j;
			return 0;
		}
		j++;
		num--;
	}
//	string qb,hb;
//	for(int i = 0;i<s.size();i++){
//		if(s.size()%2==0){
//			if(i<s.size()/2){
//				qb+=s[i];
//			}
//			else{
//				hb+=s[i];
//			}
//		}
//		else{
//			if(i<(s.size()-1)/2){
//				qb+=s[i];
//			}
//			else{
//				hb+=s[i];
//			}
//		}
//	}
//	reverse(hb.begin(),hb.end());
//	int ans=0;
//	for(int i = 0; i<qb.size(); i++){
//		if(qb[i]!=hb[i]){
//			ans++;
//		}
//	}
//	cout<<ans;
	return 0;
} 
