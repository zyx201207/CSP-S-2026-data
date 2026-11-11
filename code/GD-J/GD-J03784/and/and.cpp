#include <bits/stdc++.h>
using namespace std;
const int N=2e5+15;
long long n,m,ans=0,ceshi,s1,d[36];
map<string,int>ma;
struct node1{
	int n,m;
};
queue<node1>q;
struct node{
	int n,b=0;
	string c="";
}a[N];
vector<string>b[36];
long long ji(string s){
	int sum=0,s2=s.size(),s3=1;
	s3=1<<(s2-1);
	for(int i=0;i<s2;i++){
		if(s[i]=='1')sum+=(s3);
		s3=s3>>1;
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(d,0,sizeof(d));
	for(long long i=1;i<=n;i++){
		scanf("%d",&a[i].n);
		ceshi=a[i].n;
		s1=0;
		while(ceshi){
			a[i].c+=(char)(ceshi%2+'0');
			s1++;
			ceshi/=2;
		}
		string s2="",s3=a[i].c;
		for(int j=0;j<s1;j++){
			s2+=s3[s1-j-1];
			if(ma.find(s2)==ma.end()){
				b[j+1].push_back(s2);
			}
			d[j+1]++;
			ma[s2]++;
		}
	}
	for(int i=35;i>=1;i--){
		sort(b[i].begin(),b[i].end());
		if(d[i]>=m){
			ans=ji(b[i][b[i].size()-1]);
			int sum1=0;
			for(int j=b[i].size()-1;j>=0;j--){
				ans=ans&(ji(b[i][j]));
				sum1+=ma[b[i][j]];
				if(sum1>=m){
					cout<<ans;
					break;
				}
			}
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
