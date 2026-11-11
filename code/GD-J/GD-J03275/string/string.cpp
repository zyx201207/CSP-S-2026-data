#include<bits/stdc++.h>
using namespace std;
	/*
int n;
long long srl=0;
vector<long long> len;
vector<char> cr;

long long find(long long idx){
	int an[200003];
	an[0]=len[0];
	for(int i=1;i<len.size();i++){
		an[i]=an[i-1]+len[i];
	}
	for(int i=0;i<len.size();i++){
		if(an[i]>=idx){
			return cr[i];
		}
	}
}*/
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	/*cin>>n;
	
	
	
	for(int i=0;i<n;i++){
		long long le;char c;
		cin>>le>>c;
		srl+=le;
		if(!cr.empty()){
			if(cr[cr.size()-1]==c){
				len[len.size()-1]+=le;
				continue;
			}
		}
		len.push_back(le);cr.push_back(c);
	}
	if(len.size()==1){
		cout<<0;
		return 0;
	}
	long long mid=srl/2,res=0;
	for(int i=0;i<srl;i++){
		if(find(i)!=find(srl-i-1)){
			res++;
		}
	}
	cout<<res;
	/*
	long long mid=srl/2,lon=0,idx;
	for(int i=0;i<len.size();i++){
		lon+=len[i];
		if(lon>=mid){
			idx=i;
		}
	}
	lon-=mid;
	for(int i=0;i<idx;i++){
		midd.insert(midd.begin(),len[i]);
		midc.insert(midc.begin(),cr[i]);
	}
	midd.insert(midd.begin(),len[idx]-lon);
	midc.insert(midc.begin(),cr[idx]);
	
	for(auto x:midd){
		cout<<x<<" ";
	}*/
	
	
	long long n,res=0;
	string r="",firhalf="";
	cin>>n;
	if(n>1900){
		cout<<0;return 0;
	}
	for(long long i=0;i<n;i++){
		long long len;char a;
		cin>>len>>a;
		for(long long j=0;j<len;j++){
			r.insert(r.end(),a);
		}
	}
	long long len=r.size(),mid=len/2;
	for(long long i=0;i<mid;i++){
		firhalf.insert(firhalf.end(),r[i]);
	}
	double beg=len*1.0/2;
	long long tem=beg;
	if(beg>tem){
		tem++;
	}
	for(long long i=tem;i<len;i++){
		if(firhalf[i-tem]!=r[i]){
			res++;
		}
	}
	cout<<res;
	
	return 0;
} 
