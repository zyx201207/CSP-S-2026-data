//t2:string
//满足回文串只需要考虑它的双指针位置 
//判断考虑 O（1），O（n ai），因为n只有 2e5 
//离散 
// 中间为界 双指针遍历aij

#include <cstdio>

#include <vector>
using std::vector; 

int main(){
	
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	
	int n;scanf("%d",&n);
	
	vector < long long > inp_a (n + 2);
	vector < char > inp_c (n + 2);
	
	long long len_S = 0;
	
	for (int i = 1;i <= n;i++){
		scanf("%d %c",&inp_a [i] , &inp_c [i]);
		len_S += inp_a [i];
	}
		
	bool oe;
	if (len_S % 2 == 0) oe = false;
	else oe = true;
	
	long long len_S2 = len_S / 2;
	
	vector < long long > a (n + 5);
	vector < char > c (n + 5);
	
	int i = 1,inp_ud = 1;long long sum = 0;
	for (;sum + inp_a [inp_ud] <= len_S2;sum += inp_a [inp_ud],i++,inp_ud++)
		a [i] = inp_a [inp_ud],c [i] = inp_c [inp_ud];
	
	if (len_S2 - sum) a [i] = len_S2 - sum,	c [i] = inp_c [inp_ud],		i++;
	sum += inp_a [inp_ud];
	if (oe){
		if (sum - len_S2 > 1)
			a [i] = sum - len_S2 - 1	,	c [i] = inp_c [inp_ud]	,	i++;
	}else a [i] = sum - len_S2	,	c [i] = inp_c [inp_ud]	,	i++;
	inp_ud++;
	
	for (;inp_ud <= n;inp_ud++,i++)
		a [i] = inp_a [inp_ud],c [i] = inp_c [inp_ud];
	
	
	long long ans = 0;
	
	int l = 1,r = i - 1;
	char lc = c [l],rc = c [r];
	long long lcnt = a [l],rcnt = a [r];
	l++,r--;
	while (l <= r){
		
		if (lc != rc){
			
			if (lcnt < rcnt)
				ans += rcnt - lcnt,rcnt -= lcnt,	lcnt = a [l],lc = c [l]	,	l++;
			else if (lcnt > rcnt)
				ans += lcnt - rcnt,lcnt -= rcnt,	rcnt = a [r],rc = c [r]	,	r--;
					
			else ans += lcnt,	lcnt = a [l],rcnt = a [r]	,	lc = c [l],rc = c [r]	,	l++,r--;
			
		}else{
			if (lcnt < rcnt)
				rcnt -= lcnt,	lcnt = a [l],lc = c [l]	,	l++;
			else if (lcnt > rcnt)
				lcnt -= rcnt,	rcnt = a [r],rc = c [r]	,	r--;
					
			else lcnt = a [l],rcnt = a [r]	,	lc = c [l],rc = c [r]	,	l++,r--;
		}
		
	}
		
	printf("%lld",ans);
	
	return 0;
} 
