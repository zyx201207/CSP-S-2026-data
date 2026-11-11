#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int a,b,c[500000]={0},e[200000]={0},f=0,g=0,k,l=0,m,n=0;
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>c[i];
		if(c[i]==0){
			l++;
		}
		c[i]+=100000;
		e[c[i]]++;
		c[i]=0;
	}
	if(a==2){
		if(abs(c[0]-c[1])-b>0){
			cout<<1;
		}else{
			cout<<0;
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	e[100000]=l;
	for(int i=0;i<200000;i++){
		if(e[i]>f){
			f=e[i];
			g=i;
		}
		if(e[i]){
			c[n]=i-100000;
			n++;
		}
	}
	k=f;
	for(int i=0;i<n;i++){
		if(c[i]==g-100000){
			m=i;
		}
	}
	if(n==1){
		cout<<e[c[0]];
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	int i=1,j=1;
	if(k==1){
		m=a/2;
	}
	while(1){
		if(k*(c[m+i]-c[m])<e[c[m-j]+100000]*(c[m]-c[m-j])){
			if(b-k*(c[m+i]-c[m])>=0){
				c[m]=c[m+i];
				i++;
				k+=e[c[m-j]+100000];
				b-=k*(c[m+i]-c[m]);	
				cout<<b<<' '<<1<<endl;
			}else if(b/(c[m+i]-c[m])+e[c[m+i]+100000]>k){
				k=b/(c[m+i]-c[m])+e[m+i];
				break;
			}else{
				break;
			}
		}else{
			if(b-e[c[m-j]+100000]*(c[m]-c[m-j])>=0){
				j++;
				k+=e[c[m-j]+100000];
				b-=e[c[m-j]+100000]*(c[m]-c[m-j]);	
			}else{
				k+=b/(c[m]-c[m-j]);
				break;
			}
		}
	}
	cout<<k+1;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
