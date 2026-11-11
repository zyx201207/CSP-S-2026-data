#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

void setio(string filename,string inSu=".in",string outSu=".out"){
	string in=filename+inSu;
	string out=filename+outSu;
	freopen(in.c_str(),"r",stdin);
	freopen(out.c_str(),"w",stdout);
}

const int MAXN=2e5+10;
size_t sizelist[MAXN]={0};
char wordlist[MAXN],wordlist2[MAXN];
int difs[MAXN]={0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	setio("string");
	int num,numc=0;
	scanf("%d",&num);
	for(int i=1;i<=num;i++){
		int size;
		scanf("%d %c",&size,wordlist+i);
		if(i==1){
			sizelist[++numc]=size;
			wordlist2[numc]=wordlist[i];
		}
		else if(i!=1 && wordlist[i-1]==wordlist[i])
			sizelist[numc]+=size;
		else{
			sizelist[++numc]=size;
			wordlist2[numc]=wordlist[i];
		}
	}
	if(numc==1){
		printf("0");
		return 0;
	}
	int mid=numc>>1;
	int cnt=0;
	size_t changed1=0,changed2=0;
	if(numc%2==0){
		bool flag=true;
		for(int i=1;i<=mid;i++){
			if(!(wordlist2[i]==wordlist2[numc-i+1] && sizelist[i]==sizelist[numc-i+1])){
				flag=false;
				difs[++cnt]=i;
			}
		}
		if(flag){
			printf("0");
			return 0;
		}
		for(int i=1;i<=cnt;i++){
			changed1+=sizelist[difs[i]];
			changed2+=sizelist[numc+difs[i]-1];
		}
	}
	else if(numc%2==1){
		bool flag=true;
		for(int i=1;i<=mid+1;i++){
			if(!(wordlist2[i]==wordlist2[numc-i+1] && sizelist[i]==sizelist[numc-i+1])){
				flag=false;
				difs[++cnt]=i;
			}
		}
		if(flag){
			printf("0");
			return 0;
		}
		for(int i=1;i<=cnt;i++){
			changed1+=sizelist[difs[i]];
			changed2+=sizelist[numc+difs[i]-1];
		}
	}
	size_t changed=min(changed1,changed2);
	printf("%llu",changed);
	return 0;
}
