#include<bits/stdc++.h>
using namespace std;
const int N=2e5+15;
const bool test=0;
int n;
int s[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i]>>c[i];
	int lk=1,rk=n,l=0,r=0;
	long long res=0;
	while(lk<=rk){
		if(test) cout<<"l:"<<l<<" r:"<<r<<endl;
		if(test) cout<<"slk:"<<s[lk]<<" srk:"<<s[rk]<<endl;
		if(test) cout<<"clk:"<<c[lk]<<" crk:"<<c[rk]<<endl;
		if(test) cout<<"s["<<lk<<"]-"<<l<<":"<<s[lk]-l<<" s["<<rk<<"]-"<<r<<":"<<s[rk]-r<<endl;
		if(c[lk]==c[rk]){
			if(test) cout<<"c[lk]==c[rk]\n";
			if(s[lk]-l<s[rk]-r){
				if(test) cout<<"low\n";
				r+=s[lk]-l;
				lk++;
				l=0;
			}else if(s[lk]-l==s[rk]-r){
				if(test) cout<<"eq\n";
				lk++;
				l=0;
				rk--;
				r=0;
			}else{
				if(test) cout<<"greater\n";
				l+=s[rk]-r;
				rk--;
				r=0;
			}
		}else{
			if(test) cout<<"c[lk]!=c[rk]\n";
			if(s[lk]-l<s[rk]-r){
				if(test) cout<<"low\n";
				res+=s[lk]-l;
				r+=s[lk]-l;
				lk++;
				l=0;
			}else if(s[lk]-l==s[rk]-r){
				if(test) cout<<"eq\n";
				res+=s[lk]-l;
				lk++;
				l=0;
				rk--;
				r=0;
			}else{
				if(test) cout<<"greater\n";
				res+=s[rk]-r;
				l+=s[rk]-r;
				rk--;
				r=0;
			}
		}
		if(test) cout<<"s["<<lk<<"]-"<<l<<":"<<s[lk]-l<<" s["<<rk<<"]-"<<r<<":"<<s[rk]-r<<endl;
		if(s[lk]==l){
			lk++;
			l=0;
		}
		if(s[rk]==r){
			rk++;
			r=0;
		}
		if(test) cout<<"s["<<lk<<"]-"<<l<<":"<<s[lk]-l<<" s["<<rk<<"]-"<<r<<":"<<s[rk]-r<<endl;
	}
	cout<<res;
	fclose(stdin);
	fclose(stdout);
	return 0;
	//i wanna
}
