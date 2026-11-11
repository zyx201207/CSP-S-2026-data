#include<iostream>
using namespace std;
const long long N=500005;

int s[N],ss[N],sss[N];
int qddy(int x[],int y,int l,int k,int u){
	if(l==0)return 0;
	int o=0;
	for(int j=max(k,u);j<l;j++){
		if(x[j]!=y)o++;
	}
	if(o==l-max(k,u))return 0;
	else return 1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	//cout<<s[2];
	int u=0;
	for(int k=0;k<n;k++){
	u=k;
	for(int we=0;we<n;we++){
		sss[we]=0;
	}
	for(int i=k;i<n;i++){
		if(qddy(s,s[i],i,k,u)==1&&sss[s[i]-1]==0){
			u=i;
			sss[s[i]-1]=1;
		//	ss[s[i]-1]++;
		}
	}
	//cout<<s[2]<<endl<<ss[2]<<endl<<sss[2]<<endl;
	for(int q=u;q<n;q++){
		ss[s[q]-1]++;
	}
	//u=0;
	//cout<<sss[2];
	}
	for(int i=0;i<m;i++){
		cout<<ss[i]<<" ";
	}
	return 0;
}
