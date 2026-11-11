#include<stdio.h>

int n,m;
int a[(int)5e5+5];
int cnt[(int)5e5+5];
int desktop[(int)5e5+5];
bool putdown[(int)5e5+5];

static inline void Process(int time){
	for(int i=1;i<=n;i++){
		desktop[i]=0;
	}
	for(int i=1;i<=m;i++){
		putdown[i]=false;
	}
//	printf("---------- Round %d ----------\n",time);
	int pointer=0;
	for(int i=time;i<=n;i++){
		if(putdown[a[i]]==false){
			putdown[a[i]]=true;
			desktop[pointer++]=a[i];
		}
		else if(putdown[a[i]]==true){
			while(desktop[pointer]!=a[i]){
				pointer--;
				putdown[desktop[pointer]]=false;
			}
			desktop[pointer++]=a[i];
			putdown[a[i]]=true;
		}
//		for(int i=0;i<pointer;i++){
//			printf("%d ",desktop[i]);
//		} puts(" ");
	}
	for(int i=0;i<pointer;i++){
		cnt[desktop[i]]++;
	}
	return ;
}

static inline void Specific_A(void){
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]){
			cnt[a[i]]=i;
		}
	}
	return ;
}

static inline void Specific_m_2(void){
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			cnt1++;
		}
		else{
			cnt2++;
		}
	}
	if(cnt1>cnt2){
		printf("%d %d",n,cnt2);
	}
	else{
		printf("%d %d",cnt1,n);
	}
}

static inline bool testdata_A(void){
	for(int i=1;i<n;i++){
		if(a[i]>=a[i+1]){
			return false;
		}
	}
	return true;
}

int main(){
	#ifndef STDIO
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	#endif
//	freopen("kard.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m==1){
		printf("%d",n);
		return 0;
	}
//	if(m==2){
//		Specific_m_2();
//	}
	if(testdata_A()==true){
		Specific_A(); 
	}
	else for(int i=1;i<=n;i++){
		Process(i);
	}
	for(int i=1;i<=m;i++){
		printf("%d ",cnt[i]);
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1

Just card -> kard
?
Probably I may get about 52 points in Task 4.Such a shame that I don't know what to do if m is equal to 2.


*/
