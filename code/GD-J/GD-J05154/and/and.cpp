#include<bits/stdc++.h>
using namespace std;
int n,m,a[20005],sum,q=0,x,y;
string b[20005],c,d;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c="";
		for(int j=a[i];j>0;j=j/2){
			c+=(j%2+'0');
		}
		for(int j=c.size()-1;j>=0;j--){
			b[i]+=c[j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			d="";
			if(b[i].size()==b[j].size()){
				for(int k=0;k<b[i].size();k++){
					if(b[i][k]==b[j][k]) d+="1";
					else d+="0";
				}
			}
			else{
				x=b[i].size()-1,y=b[j].size()-1;
				if(x<y){
					for(int k=0;k<b[i].size();k++){
						if(b[i][x]==b[j][y]&&b[i][x]=='1') d+='1';
						else d+='0';
						x--,y--;
					}
				}
				else{
					for(int k=0;k<b[j].size();k++){
						if(b[i][x]==b[j][y]&&b[i][x]=='1') d+='1';
						else d+='0';
						x--,y--;
					}
				}
				
			}
			x=1,sum=0;
			for(int k=d.size()-1;k>=0;k--)
			{
				sum+=(d[k]-'0')*x;
				x*=2;
			}
			if(sum>q) q=sum;
		}
	}
	cout<<q;
	return 0;
}
