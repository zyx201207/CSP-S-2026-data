#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[200010],two[200010][35],s[200010];
void tentwo(long long x,long long i){
	for(int y=32;y>=1;y--){
		two[i][y]=x%2;
		x=x/2;
	}
}
void qing(long long ss){
	for(;ss>=1;ss--){
		two[s[ss]][1]=9;
		two[s[ss]][2]=0;
		two[s[ss]][3]=0;
		two[s[ss]][4]=0;
		two[s[ss]][5]=0;
		two[s[ss]][6]=0;
		two[s[ss]][7]=0;
		two[s[ss]][8]=0;
		two[s[ss]][9]=0;
		two[s[ss]][10]=0;
		two[s[ss]][11]=0;
		two[s[ss]][12]=0;
		two[s[ss]][13]=0;
		two[s[ss]][14]=0;
		two[s[ss]][15]=0;
		two[s[ss]][16]=0;
		two[s[ss]][17]=0;
		two[s[ss]][18]=0;
		two[s[ss]][19]=0;
		two[s[ss]][20]=0;
		two[s[ss]][21]=0;
		two[s[ss]][22]=0;
		two[s[ss]][23]=0;
		two[s[ss]][24]=0;
		two[s[ss]][25]=0;
		two[s[ss]][26]=0;
		two[s[ss]][27]=0;
		two[s[ss]][28]=0;
		two[s[ss]][29]=0;
		two[s[ss]][30]=0;
		two[s[ss]][31]=0;
		two[s[ss]][32]=0;
	}
}
void an(long long i){
	for(int y=1;y<=32;y++){
		if(!(two[i][y]==1&&two[200009][y]==1)){
			two[200009][y]=0;
		}
	}
}
void twoten(){
	int i=1;
	long long ans=0;
	for(int y=32;y>=1;y--){
		ans+=two[200009][y]*i;
		i*=2;
	}
	cout<<ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		tentwo(a[i],i);
	}

	for(int i=1;i<=32;i++){
		long long f=0,ss=0;
		for(long long j=1;j<=n;j++){
			if(two[j][i])
				f++;
			else{
				ss++;
				s[ss]=j;
			} 
		}
		if(f>=m) qing(ss);
	}
	two[200009][1]=1;
	two[200009][2]=1;
	two[200009][3]=1;
	two[200009][4]=1;
	two[200009][5]=1;
	two[200009][6]=1;
	two[200009][7]=1;
	two[200009][8]=1;
	two[200009][9]=1;
	two[200009][10]=1;
	two[200009][11]=1;
	two[200009][12]=1;
	two[200009][13]=1;
	two[200009][14]=1;
	two[200009][15]=1;
	two[200009][16]=1;
	two[200009][17]=1;
	two[200009][18]=1;
	two[200009][19]=1;
	two[200009][20]=1;
	two[200009][21]=1;
	two[200009][22]=1;
	two[200009][23]=1;
	two[200009][24]=1;
	two[200009][25]=1;
	two[200009][26]=1;
	two[200009][27]=1;
	two[200009][28]=1;
	two[200009][29]=1;
	two[200009][30]=1;
	two[200009][31]=1;
	two[200009][32]=1;
	two[n+1][1]=9;
	long long aaa=1;
	for(long long i=1;i<=n+1;i++){
		if(aaa>m){
			twoten();
			return 0;
		}
		if(two[i][1]!=9){ 
			aaa++;
			an(i);
		}
	}
	cout<<0;
	return 0;
}


