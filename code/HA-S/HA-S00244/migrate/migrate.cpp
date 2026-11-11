#include<bits/stdc++.h>
using namespace std;
long long d;
int times(int l,int q,int w,int na[100001],int st){
	int s=0;
	for(int i=st;i<=l;){
		long long sum=0;
		for(int j=i;j<=l;j++){
			if(j==l){
				i=l+1;
				s++;
				break;
			}
			if(q&&sum+na[j+1]>d&&s==w){
				if(i==j-1||i==j){
					return -1;
				}
				i=j-1;
				s++;
				sum=0;
				break;
			}else if(sum+na[j+1]>d){
				i=j;
				s++;
				sum=0;
				break;
			}
			sum+=na[j];
		}
	}
	return s;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,fl=0,sum=0;
	cin>>c>>t;
	while(t--){
		int n,s1=0,s2=0,lenb=0,n1[100001]={0};
		long long a,b;
		cin>>n>>d>>a;
		for(int i=0;i<n-1;i++){
			cin>>b;
			n1[i]=b-a;
			a=b;
			lenb++;
		}
		for(int z=0;z<lenb-2;z++){
			sum=0;
			for(int l=z+2;l<=lenb;l++){
				s1=times(l+1,0,-1,n1,z);
				for(int i=0;i<s1;i++){
					s2=times(l+1,1,i,n1,z);
					if(s2==s1){
						fl++;
						break;
					}
				}
				if(fl){
					sum++;
					fl--;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
