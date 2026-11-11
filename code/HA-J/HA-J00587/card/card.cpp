#include <bits/stdc++.h>

using namespace std;
const int N=5e5+10;
int n,m,a[N],sum[N],mk[N],b[N];
stack <int> st;

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n<=5000){
		for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!mk[a[j]]){
				mk[a[j]]=1;
				st.push(a[j]);
				b[a[j]]++;
			}else{
				while(!st.empty()&&st.top()!=a[j]){
					b[st.top()]--;
					if(!b[st.top()]) mk[st.top()]=0;
					st.pop();
				} 
			}
		}
		while(!st.empty()){
			sum[st.top()]++;
			st.pop();
		}
		memset(mk,0,sizeof(mk));
		memset(b,0,sizeof(b));
	}
	}else{
		if(m<=2){
			for(int i=1;i<=n;i++){
				if(a[i]==a[n]) sum[a[i]]++;
				else sum[1]++,sum[2]++;
			}	
		}else{
			bool A=1;
			for(int i=1;i<n;i++) if(a[i]>a[i+1]) A=0;
			if(A){
				for(int i=1;i<=n;i++) sum[a[i]]++;
				for(int i=1;i<=m;i++) sum[i]+=sum[i-1];
			}else{
				for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!mk[a[j]]){
				mk[a[j]]=1;
				st.push(a[j]);
				b[a[j]]++;
			}else{
				while(!st.empty()&&st.top()!=a[j]){
					b[st.top()]--;
					if(!b[st.top()]) mk[st.top()]=0;
					st.pop();
				} 
			}
		}
		while(!st.empty()){
			sum[st.top()]++;
			st.pop();
		}
		memset(mk,0,sizeof(mk));
		memset(b,0,sizeof(b));
	}
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<" ";
	return 0;
}
