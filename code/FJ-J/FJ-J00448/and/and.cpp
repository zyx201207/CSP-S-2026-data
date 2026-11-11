#include<bits/stdc++.h>
using namespace std;
int n,m,a[(int)2e5+10],ma;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(m==1)
		for(int i=1;i<=n;i++)ma=max(ma,a[i]);
	else if(m==n){
		ma=a[1];
		for(int i=2;i<=n;i++)ma=a[i]&ma;
	}
	else if(m==2)
		for(int i=2;i<=n;i++)
			for(int j=1;j<i;j++)
				ma=max(ma,a[i]&a[j]);
	else if(m==3)
		for(int i=3;i<=n;i++)
			for(int j=2;j<i;j++)
				for(int k=1;k<j;k++)
					ma=max(ma,a[i]&a[j]&a[k]);		
	else if(m==4)
		for(int i=4;i<=n;i++)
			for(int j=3;j<i;j++)
				for(int k=2;k<j;k++)
					for(int l=1;l<k;l++)
						ma=max(ma,a[i]&a[j]&a[k]&a[l]);	
	else if(m==n-1)
		for(int i=1;i<=n;i++){
			int s=pow(2,21)-1;
			for(int j=1;j<=n;j++)
				if(j!=i)s&=a[j];
			ma=max(ma,s);
		}
	else if(m==n-2)
		for(int i=2;i<=n;i++)
			for(int j=1;j<i;j++){
				int s=pow(2,21)-1;
				for(int k=1;k<=n;k++)
					if(k!=i&&k!=j)s&=a[k];
				ma=max(ma,s);				
			}	
	else if(m==n-3)
		for(int i=3;i<=n;i++)
			for(int j=2;j<i;j++)
				for(int k=1;k<j;k++){
					int s=pow(2,21)-1;
					for(int o=1;o<=n;o++)
						if(o!=i&&o!=j&&o!=k)s&=a[o];
					ma=max(ma,s);					
				}
	else if(m==5)
		for(int i=5;i<=n;i++)
			for(int j=4;j<i;j++)
				for(int k=3;k<j;k++)
					for(int l=2;l<k;l++)
						for(int p=1;p<l;p++)
							ma=max(ma,a[i]&a[j]&a[k]&a[l]&a[p]);
	else if(m==6)
		for(int i=6;i<=n;i++)
			for(int j=5;j<i;j++)
				for(int k=4;k<j;k++)
					for(int l=3;l<k;l++)
						for(int p=2;p<l;p++)
							for(int q=1;q<p;q++)
								ma=max(ma,a[i]&a[j]&a[k]&a[l]&a[p]&a[q]);
	else if(m==7)
		for(int i=7;i<=n;i++)
			for(int j=6;j<i;j++)
				for(int k=5;k<j;k++)
					for(int l=4;l<k;l++)
						for(int p=3;p<l;p++)
							for(int q=2;q<p;q++)
								for(int o=1;o<q;o++)
									ma=max(ma,a[i]&a[j]&a[k]&a[l]&a[p]&a[q]&a[o]);
	printf("%d",ma);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

