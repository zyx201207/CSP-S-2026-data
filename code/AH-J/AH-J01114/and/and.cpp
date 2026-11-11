#include<bits/stdc++.h>
using namespace std;

int n,m,a,nun;
string b[200001];

string dtb(int x){//转二进制
	//string s="";
	string s="%";
	while(x!=0){
		
		if(x%2)s+='1';
		else s+='0';
		
		
		//if(x%2)s+=1;
		//else s+=0;
		x=x/2;
	}
	int n=s.size();
	for(int i=1;i*2<=n;i++)swap(s[i],s[n-i]);
	//for(int i=0;i*2<n;i++)swap(s[i],s[n-i-1]);
	return s;
}

int btd(string s){//转十进制
	int n=s.size(),x=1,ans=0;
	if(s[n])ans++;
	//cout<<endl<<ans<<endl;
	for(int i=n-1;i>=1;i--){
		ans+=(s[i]-48)*x,x=x*2;
		//cout<<ans<<endl;
	}
	return ans;
}

string an(string x,string y){//求和
	int n=x.size(),m=y.size();
	if(!(n>=m)){swap(n,m);swap(x,y);}
	//for(int i=n-m+1;i<=n;i++)x[i]=x[i]&&y[i-(n-m)];
	
	for(int i=n-m+1;i<=n;i++)if(x[i]=='1'&&y[i-(n-m)]=='1')x[i]='1';else x[i]='0';
	
	return x;
}

string ma(string x,string y){//取max
	int n=x.size(),m=y.size();
	if(n>m)return x;
	if(n<m)return y;
	for(int i=1;i<=n;i++)
		if(x[i]!=y[i])
			if(x[i]>y[i])return x;
			else return y;
		else continue;
	return x;
}

struct v{
	int l,r,ls,rs;
	string a;
}xxxxx;
vector<v> x;

void adding(int l,int r,int ls,int rs,string a){//加节点
	v p;
	p.l=l;
	p.r=r;
	p.ls=ls;
	p.rs=rs;
	p.a=a;
	x.push_back(p);
	return ;
}

void bu(){//建树
	nun=n;
	x.push_back(xxxxx);
	//基层
	for(int i=1;i<=n;i++){
		adding(i,i,0,0,b[i]);
		//cout<<i<<' '<<x[i].l<<' '<<x[i].r<<' '<<x[i].ls<<' '<<x[i].rs<<' '<<x[i].a<<endl;
		}
	
	for(int i=1;i<nun;i+=2){
		nun++;
		
		adding(x[i].l,x[i+1].r,i,i+1,an(x[i].a,x[i+1].a));
		
		}
	return;
}

string re(int i,int l,int r){
	int mid=x[x[i].ls].r;
	if(x[i].l==l&&x[i].r==r)return x[i].a;//命中
	if(r<=mid)return(re(x[i].ls,l,r));//全部于左
	if(l>mid)return(re(x[i].rs,l,r));//全部于右
	//trans
	return(an( re(x[i].ls,l,mid),re(x[i].rs,mid+1,r) ));
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		b[i]=dtb(a);
		}
	/*
	cout<<b[3]<<endl;
	cout<<ma(b[1],b[2])<<endl;
	cout<<an(b[1],b[3]);
	*/
	
	bu();
	//cout<<nun<<endl;
	
	string MAX;
	for(int i=1;i<=n-m;i++){
		MAX=re(nun,i,i+m);
		}
	//cout<<MAX;
	
	cout<<btd(MAX);
	//cout<<endl<<an(b[2],b[3]);
	//'1'==48
	return 0;
}
