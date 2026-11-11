#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int read(){
	int t;
	scanf("%d",&t);
	return t;
} 
struct Pair{
	char c;
	int a;
};
int n;
Pair s[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	long long p=1,q=0;
	for(int i=1;i<=n;i++){
		int a1;
		char c1;
		cin>>a1>>c1;
		s[i].a=a1,s[i].c=c1;
		p+=a1;
	} 
	int i=1,j=n;
	long long pi=s[1].a,qi=s[n].a;
	long long sum=0;
	while(i<j){
		bool b=s[i].c!=s[j].c;
		if(pi==qi){
			p+=pi,q-=pi;
			if(b) sum+=pi;
			i++,j--;
			pi=s[i].a,qi=s[j].a;
		}
		else if(pi<qi){
			p+=pi,q-=pi;
			qi-=pi; 
			if(b) sum+=pi;
			i++;
			pi=s[i].a;
		}
		else{
			p+=qi,q-=qi;
			if(b) sum+=qi;
			pi-=qi; 
			j--;
			qi=s[j].a;
		}
		//cout<<pi<<' '<<qi<<endl;
	}
	cout<<sum;
	return 0;
}
