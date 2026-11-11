#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s[500010],la[500010],ans[500010],cnt;//last_appear
stack<long long> t;
long long count_num(stack<long long> x){
	long long ans;
} 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		la[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(s[a[i]]==0){
			t.push(a[i]);	
			s[a[i]]=1;
		}else{
			s[a[i]]=0;
			while(!t.empty()&&t.top()!=a[i]){
				la[t.top()]=0;
				t.pop();
			}
			if(la[a[i]]<=i)ans[a[i]]++;
		}
	}
	return 0;
}
