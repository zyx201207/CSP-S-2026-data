#include<bits/stdc++.h>
using namespace std;
struct ccf{
	long long a;
	char c;
}k[200005];
long long n,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>k[i].a>>k[i].c;
	int i=1,j=n,a1,a2;
	while(i<=j){
		//cout<<i<<" "<<j<<" ";
		//cout<<k[i].a<<" "<<k[i].c<<endl;
		//cout<<k[j].a<<" "<<k[j].c<<endl;
		a1=max(k[i].a,k[j].a),a2=min(k[i].a,k[j].a);
		//cout<<a1<<" "<<a2<<endl; 
		if(k[i].c!=k[j].c){
			cnt+=a1-a2;
			if(k[i].a<k[j].a){
				k[j].a=k[j].a-k[i].a;
				i++;
				//cout<<1<<" "<<k[j].a<<" "<<k[i].a<<endl;
			}
			else if(k[i].a==k[j].a)
				cnt+=a1,i++,j--;
			else{
				k[i].a=k[i].a-k[j].a;
				j--;
				//cout<<2<<" "<<k[i].a<<" "<<k[j].a<<endl;
			}	
		}	
		else 
			i++,j--;
	}
	cout<<cnt<<endl;
	return 0;
}

