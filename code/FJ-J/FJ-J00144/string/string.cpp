/*Η ΠΟΛΗ ΕΠΕΣΕ, ΜΑ ΤΟ ΦΟΣ ΔΕΝ ΣΒΙΝΕΙ
Ο ΒΑΣΙΛΙΑΣ ΖΙ ΣΤΙΝ ΚΑΡΔΙΑ
ΦΥΛΑΚΕΣ ΠΙΣΤΗΣ ΚΕ ΔΟΞΑΣ
ΣΑΝ ΑΣΤΡΑΠΙ ΘΑ ΕΡΘΕΙ*/
#include<bits/stdc++.h>
#define int long long
#define si set<int>
#define vi vector<int>
#define vp vector<pair<int,char> >
using namespace std;
int n;
vp v,lf,rg;
vi w;
void rp(int rp){
	while(1)rp++;
}
void align(vp v,int s,vp& lf,vp& rg,vi& w){
	vp l1,r1;
	si d;
	int t=0;
	for(auto &p:v){
		t+=p.first;
		d.insert(t);
		if(t<=s/2)l1.push_back(p);
		else if(t>s/2&&p.first>t-s/2){
			l1.push_back(make_pair(p.first-t+s/2,p.second));
			d.insert(s/2);
			break;
		}
	}
	reverse(v.begin(),v.end());
	t=0;
	for(auto &p:v){
		t+=p.first;
		d.insert(t);
		if(t<=s/2)r1.push_back(p);
		else if(t>s/2&&p.first>t-s/2){
			r1.push_back(make_pair(p.first-t+s/2,p.second));
			d.insert(s/2);
			break;
		}
	}
	int lpt=0,rpt=0;
	for(int x:d)if(x<=s/2)w.push_back(x);
	for(int i=w.size();i>=1;i--)w[i]-=w[i-1];
	for(int x:w){
		if(l1[lpt].first==x){
			lf.push_back(make_pair(x,l1[lpt++].second));
		}
		else if(l1[lpt].first>x){
			lf.push_back(make_pair(x,l1[lpt].second));
			l1[lpt].first-=x;
		}
		if(r1[rpt].first==x){
			rg.push_back(make_pair(x,r1[rpt++].second));
		}
		else if(r1[rpt].first>x){
			rg.push_back(make_pair(x,r1[rpt].second));
			r1[rpt].first-=x;
		}
	}
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,s=0;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;char c;
		cin>>a>>c;
		s+=a;
		v.push_back(make_pair(a,c));
	}
	align(v,s,lf,rg,w);
	int ans=0;
	for(int i=0;i<lf.size();i++)if(lf[i].second!=rg[i].second)ans+=w[i];
	cout<<ans<<endl;
	return 0;
}

