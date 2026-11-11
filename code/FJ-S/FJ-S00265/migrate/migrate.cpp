#include<bits/stdc++.h>
using namespace std;
int f,t;
int main(){
	ifstream fin("migrate.in");
	ofstream fout("migrate.out");
	fin>>f>>t;
	while(t--){
		int ans=0; 
    	long long int n,d;
		fin>>n>>d;
		long long int a[n]={0};
		int c;
		for(int i=0;i<n;i++){
			fin>>a[i];
		} 
		long long int b[n];
		
		for(int p=2;p<n;p++){
			b[n]={0};
			b[p-2]=0;
			if(a[p]-a[p-1]>d){
				b[p-1]=0;
			}else{
				b[p-1]=1;
			}
		    int zkx=p-2;
			for(int i=p;i<n;i++){
			    int kjy=INT_MAX;
			    while(a[i]-a[zkx]>d){
				    zkx++;
			    }
				if(zkx==i){
					b[zkx]=0;
					break;				
				} 
			    c=1;
			    for(int j=zkx;j<i;j++){
				    if(kjy==b[j]){
					    c++;
				    }
				    if(kjy>b[j]){
					    kjy=b[j];
					    c=1;
				    }							
			    }
			    b[i]=kjy+1;
			    if(c==2){
				    ans++;
			    }
		    }
		}
		fout<<ans<<endl;
	}
	return 0;
} 
