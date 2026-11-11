#include<bits/stdc++.h>
#include<string>
using namespace std;
long long n,m,mxl,v[200010],t=0;
string s[200010],ss[200010],ans;
string ad(string xss,string yss){
	int len=max(xss.size(),yss.size());
	string newstr="";
	for(int i=0;i<len;i++){
		if(xss[i]=='1'&&yss[i]=='1') newstr+='1';
		else newstr+='0';
	}
	return newstr;
}
void ttt(int x,int ijk){
	int k=0;
	string tmpst="";
	while(x!=0){
		if(x%2==0){
			x/=2;
			tmpst[k++]+='0';
		}else{
			x/=2;
			tmpst[k++]+='1';
		}
	}
	k--;
	for(int j=0;j<k;j++){
		s[ijk]+=tmpst[j];
	}
}
long long etos(string abc){
	long long len=abc.size(),tmp=1,ans;
	for(int i=0;i<n;i++){
		if(abc[i]=='1') ans+=tmp;
		tmp*=2;
	}
	return ans;
}
bool cmp(string ss1,string ss2){
	if(ss1.size()>ss2.size()) return false;
	if(ss1.size()<ss2.size()) return true;
	int len=ss1.size();
	while(len!=0){
		if(ss1[len]<ss2[len]) return false;
		if(ss1[len]>ss2[len]) return true;
		len--;
	}
}
long long summ(long long i,long long mx){
	int ans=0;
	for(int j=i;j<=mx;j++) ans+=v[j];
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    cin>>n>>m;
    for(int i=0,x;i<n;i++){
    	cin>>x;
    	ttt(x,i);
    	mxl=max(mxl,(long long)s[i].size());
    	v[s[i].size()]++;
	}
	for(int i=mxl-1;i>=0;i--){
		if(summ(i,mxl)>=m){
			for(int j=0;j<n;j++){
				if(s[j].size()>=i){
					ss[++t]=s[j];
				}
			}
			break;
		}
	}
	sort(ss+1,ss+t+1,cmp);
	for(int i=0;i<m;i++){
		if(i==1) ans=ss[i];
		else ans=ad(ans,ss[i]);
	}
	cout<<etos(ans);
	return 0;
}
