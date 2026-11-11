//t1:travel
//变量都是一一对应的
//选择结构可
//其中，第i+1个问题可视为第i个问题的衍生 

#include <cstdio>
#include <algorithm>
#include <cmath>

static int cm [258];
static int cm_1 [258];

void prepare_c(void){
	cm ['A'] = 1,cm ['B'] = 1,cm ['C'] = 1;
	cm ['D'] = 2,cm ['F'] = 2;
	cm_1 ['A'] = 1,cm_1 ['B'] = 2,cm_1 ['C'] = 3;
	cm_1 ['D'] = 4,cm_1 ['F'] = 5;
}

int main(){
	
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	
	prepare_c();
	
	char r_t [10],x_t [10];	char r_s [10],x_s [10];
	scanf("%s %s",&r_t,&r_s);
	scanf("%s %s",&x_t,&x_s);
	
	int r_1 = 0,r_2 = 0;char r3;
	int x_1 = 0,x_2 = 0;char x3;
	
	for (int i = 0;r_t [i] != '\0';i++,r_1 *= 10)
		r_1 += ((int)r_t [i]) - 48;
	for (int i = 0;x_t [i] != '\0';i++,x_1 *= 10)
		x_1 += ((int)x_t [i]) - 48;
	r_1 /= 10,x_1 /= 10;
	
	
	if (r_1 != x_1){
		printf("0000");
		return 0;
	}else printf("1");
	
	
	int ir = 0,ix = 0;
	for (;!(r_s [ir] >= 65 && r_s [ir] <= 70);ir++,r_2 *= 10)
		r_2 += ((int)r_s [ir]) - 48;
	for (;!(x_s [ix] >= 65 && x_s [ix] <= 70);ix++,x_2 *= 10)
		x_2 += ((int)x_s [ix]) - 48;
	r3 = r_s [ir], x3 = x_s [ix];
	r_2 /= 10,x_2 /= 10;
	
	if (r_2 != x_2){
		printf("000");
		return 0;
	}else printf("1");
	
	
	if (cm [r3] == cm [x3]) printf("1");
	else {
		printf("00");
		return 0;
	}
	
	
	if (std::abs(cm_1 [r3] - cm_1 [x3]) == 1) printf("1");
	else {
		printf("0");
		return 0;
	}
	
	return 0;
}
