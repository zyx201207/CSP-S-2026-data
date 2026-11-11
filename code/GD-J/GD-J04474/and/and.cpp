#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200005],cnt;
string s,s1;
bool rev=0;
int maxa=0;	 	
string yy(int u){
	string s2;
	while(u!=0){
		int we=u%2;
		s2+=to_string(we);
		u/=2;
	}
	reverse(s2.begin(),s2.end());
	return s2;
}
string hb(string x,string y){
	int lenx=x.size(),leny=y.size();
	if(lenx!=leny){
		if(lenx>leny){
			reverse(y.begin(),y.end());
			for(int i=0;i<lenx-leny;i++){
				y+=to_string(0);
			}
			reverse(y.begin(),y.end());
		}else{
			reverse(x.begin(),x.end());
			for(int i=0;i<leny-lenx;i++){
				x+=to_string(0);
			}
			reverse(x.begin(),x.end());
		}
		//cout<<x<<" "<<y<<endl;
	}
	string s3;
	int len=max(lenx,leny);
	for(int i=0;i<len;i++){
		if(x[i]==y[i]&&x[i]=='1'&&y[i]=='1'){
			s3+=to_string(1);
		}else{
			s3+=to_string(0);
		}
	}
	//cout<<s3;
	return s3;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	cnt=maxa;
	sort(a+1,a+1+n,greater<int>());
	if(m==1){
		cout<<maxa;
		return 0;
	}
	while(maxa!=0){
		int we=maxa%2;
		s+=to_string(we);
		maxa/=2;
	//	cout<<s;
	}
	reverse(s.begin(),s.end());
	for(int i=2;i<=m;i++){
		s1=yy(a[i]);
		s=hb(s,s1);
		s1="";
	}
	cnt=0;
	reverse(s.begin(),s.end());
	int se=s.size();
	for(int i=0;i<se;i++){
		cnt+=pow(2,i)*(s[i]-'0');
	}
	//
	cout<<cnt;
	return 0;
}

