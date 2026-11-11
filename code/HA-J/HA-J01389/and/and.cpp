#include<bits/stdc++.h>
using namespace std;
string totwo(long long x){
	string s="";
	while(x!=0){
		int ot=x%2;
		char c=ot+'0';
		s=c+s;
		x/=2;
	}
	return s;
}
int toten(string x){
	long long ansnum=0;
	long long cnt=0;
	for(long long i=x.size()-1;i>=0;i--){
		ansnum+=(x[i]-'0')*pow(2,cnt);
		cnt++;
	}
	return ansnum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n,m;
	long long a[100000000];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	long long maxn=-1;
	for(long long i=0;i<n-1;i++){
		for(long long j=i+1;j<n;j++){
			
			string p=totwo(a[i]);
			string q=totwo(a[j]);
			long long pL=p.size();
			long long qL=q.size();
			if(pL>qL){
				for(long long x=0;x<pL-qL;x++){
					q="0"+q;
				}
			}else if(pL<qL){
				for(long long x=0;x<qL-pL;x++){
					p="0"+p;
				}
			}
			string anst="";
			for(long long x=0;x<p.size();x++){
				if(p[i]==q[i]&&p[i]!='0'&&q[i]!='0'){
					anst+="1";
				}else{
					anst+="0";
				}
			}
			if(toten(anst)>maxn){
				maxn=toten(anst);
			}
		}
	}
	cout<<maxn;
	return 0;
}
