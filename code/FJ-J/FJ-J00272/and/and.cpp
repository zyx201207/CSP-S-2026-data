#include<bits/stdc++.h>
using namespace std;
int n,m,f=1,sum,len;

struct data{
	string s;
	int k,cnt,ant;
}a[200010];

string qwer(int p,int q){
	string ss="";
	while(p!=0){
		a[q].ant++;
		ss+=p%2;
		if(p%2==1){
			a[q].cnt++;
		}
		p/=2;
	}
	return ss;
}

bool cmp(data x,data y){
	if(x.ant<y.ant){
		return true;
	}else if(x.ant==y.ant&&x.cnt<y.cnt){
		return true;
	}else{
		return false;
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		cin>>a[i].k;
	}
	
	for(int i=0;i<n;i++){
		a[i].s=qwer(a[i].k,i);
	}
	
	sort(a,a+n,cmp);
	
	for(int i=1;i<m;i++){
		len=min(a[i].s.size(),a[i-1].s.size());
	}
	
	for(int i=0;i<len;i++){
		for(int j=1;j<m;j++){
			if(a[j-1].s[i]!=a[j].s[i]){
				f=0;
				break;
			}
		}
		sum+=f*pow(2,i);
	}
	
	cout<<sum;
	
	return 0;
}
