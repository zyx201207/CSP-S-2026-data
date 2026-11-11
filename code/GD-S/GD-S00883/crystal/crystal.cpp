#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>

static inline long long int max(long long int f,long long int s){
	return f>s?f:s;
}

static inline long long int min(long long int f,long long int s){
	return f<s?f:s;
}

int n;
long long int m,maxup;
long long int a[(int)5e5+5];
int ans=0;

static void dfs(int now,long long int last){
	if(last<0){
		return ;
	}
//	printf("now %d, last %d\n",now,last);
//	puts("+++");
	if(last==0 || now==n+1){
//		printf("Got, ");
//		for(int i=1;i<=n;i++){
//			printf("%d, ",a[i]);
//		} puts(" ");
		long long int * mirror=(long long int * )calloc(n+1,sizeof(long long int));
		for(int i=1;i<=n;i++){
			mirror[i]=a[i];
		}
		std::sort(mirror+1,mirror+n+1);
		long long int maxcnt=0,cnt=0;
		mirror[0]=mirror[1];
		for(int i=1;i<=n;i++){
			if(mirror[i]==mirror[i-1]){
				cnt++;
			}
			else{
				maxcnt=max(maxcnt,cnt);
				cnt=1;
			}
		}
		maxcnt=max(maxcnt,cnt);
		ans=max(ans,maxcnt);
		free(mirror);
//		printf("maxcnt %d, ans %d\n",maxcnt,ans);
		return ;
	}
	for(int i=0;i<=m;i++){
		if(last-i<0){
			continue;
		}
//		printf("now %d, add %d, less %d\n",now,i,last-i);
		a[now]+=i;
		dfs(now+1,last-i);
		a[now]-=i;
	}
	return ;
}

static inline void solve_A(void){
	int ans=0;
	for(int i=n-1;i>=1;i--){
		m-=(n-i);
		if(m<0){
			break;
		}
		ans++;
	}
	ans++;
	printf("%d",ans);
}

static inline void solve_B(void){
	int ans=0;
	long long int delta=a[2]-a[1];
	for(int i=n-1;i>=1;i--){
		m-=((long long int)n-(long long int)i)*delta;
		if(m<0){
			break;
		}
		ans++;
	}
	ans++;
	printf("%d",ans);
}

static inline bool testdata_A(void){
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			return false;
		}
	}
	return true;
}

static inline bool testdata_B(void){
	long long int delta=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=delta){
			return false;
		}
	}
	return true;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	std::sort(a+1,a+n+1);
	if(n<=5 && m<=10){
		dfs(1,m);
		printf("%lld",ans); 
	}
	else if(testdata_A()==true){
		solve_A();
	}
	else if(testdata_B()==true){
		solve_B();
	}
	else{
		printf("%d",n);
	}
	return 0;
}
/*
5 5
1 2 4 8 9

It is no doubt that it is quite super horrible if I cannot get enough grades to go to NOIP.

What about Specific data A?

For each place i in array a_i, the space the M need to fill is 
$$
s = n - i
$$
The best way I think is to fill these spaces from high to low until the M runs out.

Oh, if it can?It 'll be fantastic.
Look this example:
5 10
1 2 3 4 5
A method is that 1 + 2 + 3 + 4 = 10.That's correct.
How about:
5 4
1 2 3 4 5
A method is that 1 + 2 = 3 < 4. That's also correct.
Let's go....

the function "solve_A" is finished.The Specific data B is also may be solved by me.Oh 's too hard.
Observe the example first.
5 7
1 3 5 7 9
Answer : 3
Look so cute, for each i in array "a_i", there's the paid:
$$
s = (n - i) \cdot \Delta
$$
Oh yeah!Let's goooooooooooooo.

Glad + Scared = Helpless

My total grade: 40 + 32 + 24 = 108 points away from OI world.

What about HBCPC 2024 Genshin Impact Startup Forbidden III ?
//freopen//freopen//freopen//freopen//freopen,remember to write freoepn
*/
