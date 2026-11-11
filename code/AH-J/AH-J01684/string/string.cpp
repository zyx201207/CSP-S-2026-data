#include<bits/stdc++.h> 
using namespace std;
long long a,b[200005],b1[200005];
char c,d[200005],d1[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int j=1;char s;
	cin>>a>>c;
	s=c;d[1]=s;
	b[1]=a;
	for(int i=2;i<=n;i++){
		cin>>a>>c;
		if(c==s) b[j]+=a;
		else{
			b[++j]=a;
			s=c;
			d[j]=s;
		}
    }
    for(int i=1,k=j;i<=j,k>=1;i++,k--){
    	d1[k]=d[i];
    	b1[k]=b[i];
	}
	long long sum1=b[1],sum2=b1[1],k=1,i=1,ans=0;
    while(i<=j&&k<=j){
    	if(d[i]!=d1[k]){
    		if(sum2>=sum1){
    			if(sum2-b1[k]<=sum1-b[i]) ans+=b[i];
    			else ans+=b1[k]-(sum2-sum1);
			}
			else{
				if(sum1-b[i]<=sum2-b1[k]) ans+=b1[k];
				else ans+=b[i]-(sum1-sum2);
			}
		}
		if(sum1<=sum2) {
			i++;
			sum1+=b[i];
		}
		else if(sum2<sum1){
			k++;
			sum2+=b1[k];
		}
	}
	cout<<ans/2;
	return 0;
}
