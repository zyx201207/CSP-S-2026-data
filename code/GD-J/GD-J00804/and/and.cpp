#include<stdio.h>
#include<queue>
#include<algorithm>

static inline int max(int f,int s){
	return f>s?f:s;
}

static inline int popcount(int param){
	return __builtin_popcount(param);
}

int n,m;
int array[(int)2e5+5];

class SegmentTree{
	int d[(int)1e6+5];
public:
	void Build(int p,int l,int r){
		if(l==r){
			d[p]=array[l];
			return ;
		}
		int mid=(l+r)>>1;
		Build(p<<1,l,mid);
		Build(p<<1|1,mid+1,r);
		d[p]=d[p<<1]&d[p<<1|1];
		return ;
	}
	
	inline int Query(int L,int R,int l,int r,int p){
		if(L>R || l>r){
			return 0;
		}
		if(L<=l && R>=r){
			return d[p];
		}
		int mid=(l+r)>>1;
		int ret;
		bool left=false;
		if(L<=mid){
			ret=Query(L,R,l,mid,p<<1);
			left=true;
		}
		if(R>mid){
			if(left==false){
				ret=Query(L,R,mid+1,r,p<<1|1);
			}
			else{
				ret&=Query(L,R,mid+1,r,p<<1|1);
			}
		}
		return ret;
	}
};
SegmentTree st;

static inline void solve1(void){
	long long int ans=0;
	for(int mask=0;mask<(1<<n);mask++){
		if(popcount(mask)!=m){
			continue;
		}
		long long int temp=0;
		bool first=false;
		for(int j=0;j<n;j++){
			if(mask & (1<<j)){
	//			printf("c %d\n",j);
				if(first==false){
					temp=array[j+1];
					first=true; 
				}
				else{
					temp=temp&array[j+1];
				}
			}
		}
	//	printf("mk %d, temp %d\n",mask,temp);
		if(ans<temp){
			ans=temp;
		}
	}
	printf("%lld",ans);
	return ;
}

static inline void solve2_m_1(void){
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,array[i]);
	}
	printf("%d",ans);
	return ;
}

static inline void solve2_m_2(void){
	int ans=0;
	for(int l=1;l<=n;l++){
		for(int r=1;r<=n;r++){
			if(l==r){
				continue;
			}
			ans=max(ans,array[l]&array[r]);
		}
	}
	printf("%d",ans);
	return ;
}

static inline void solve2_m_n(void){
	int ans=array[1];
	for(int i=2;i<=n;i++){
		ans&=array[i];
	}
	printf("%d",ans);
	return ;
}

static inline void solve3_m_n_1(void){
	st.Build(1,1,n);
	int ans=0;
	for(int i=1;i<=n;i++){
		int sum=0;
		if(i==1){
			sum=st.Query(i+1,n,1,n,1);
		}
		else if(i==n){
			sum=st.Query(1,i-1,1,n,1);
		}
		else{
			sum=st.Query(1,i-1,1,n,1)&st.Query(i+1,n,1,n,1);
		}
		ans=max(ans,sum);
	}
	printf("%d",ans);
	return ;
}

static inline void solve3_A(void){
	std::sort(array+1,array+n+1,[](const int & f,const int & s){
		return f>s;
	});
	int ans=array[1];
	for(int i=2,cnt=2;i<=n && cnt<=m;i++,cnt++){
		ans&=array[i];
	}
	printf("%d",ans);
	return ;
}

static inline void solve3_B(void){
	int ans=array[n];
	for(int i=n-1,cnt=2;i>=1 && cnt<=m;i--,cnt++){
		ans&=array[i];
	}
	printf("%d",ans);
	return ;
}

static inline void solve3_4(void){
	std::sort(array+1,array+n+1,[](const int & f,const int & s){
		return f>s;
	});
	int ans=array[1];
	for(int i=2,cnt=2;i<=n,cnt<=m;i++,cnt++){
		ans&=array[i];
	}
	printf("%d",ans);
	return ;
}

static inline void solve3_try(void){
	std::sort(array+1,array+n+1,[](const int & f,const int & s){
		return f>s;
	});
	int ans=array[1];
	for(int i=2,cnt=2;i<=n,cnt<=m;i++,cnt++){
		ans&=array[i];
	}
	printf("%d",ans);
}

static inline bool testdata_B(void){
	for(int i=1;i<=n;i++){
		if(array[i]!=i-1){
			return false;
		}
	}
	return true;
}

static inline bool Div(int param){
	int value=param+1;
	while(true){
		if(value==1){
			break;
		}
		int s=value/2;
		if(s*2!=value){
			return false;
		}
		value/=2;
	}
	return true;
}

static inline bool testdata_A(void){
	for(int i=1;i<=n;i++){
		if(Div(array[i])==false){
			return false;
		}
	}
	return true;
}

static inline bool testdata_less_4(void){
	for(int i=1;i<=n;i++){
		if(array[i]>4){
			return false;
		}
	}
	return true;
}

int main(){
	#ifndef STDIO
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&array[i]);
	}
	if(n<=20){
		solve1();
		return 0;
	}
	if(n<=2000){
		if(m==1){
			solve2_m_1();
			return 0;
		}
		if(m==2){
			solve2_m_2();
			return 0;
		}
		if(m==n){
			solve2_m_n();
			return 0;
		}
		return 0;
	}
	if(m==n-1){
		solve3_m_n_1();
		return 0;
	}
	if(testdata_B()==true){
		solve3_B();
		return 0;
	}
	if(testdata_A()==true){
		solve3_A();
		return 0;
	}
	if(testdata_less_4()==true){
		solve3_4();
		return 0;
	}
	else{
		solve3_try();
	}
	return 0;
}
/*
Wow, there are 273 lines of codes in this file, it is such a big special-testdata cases selector.

Man, what can I say?

the Best grade I can get : 50 + 85 + 68 + 100 = 303 points.
What about the worst? 52 + 70 + 68 + 100 = 290 points.
Just Away from OI World.
How about deal with the Task 2: String ? But it's totaly had for me.

The Virtual Box is so slow that it used about 20 minutes to boot the system.

The, hmm, or if I igore the result value of the function "scanf"? It is such a good idea.

Otherwise, every codes Compile Error Judge result lead to a bad grade, I 'd better check them up.
Remember, I wanna play the "Mondstadt Act 3:the Song of Dragon and Freedom" after going back to the hotel.
And prepare for the CSP-S 2026 in the afternoon.
 
qwq
*/
