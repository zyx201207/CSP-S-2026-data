#include <cstdio>
char temp[14], xiang1[2], xiang2[2], pai1[2], pai2[2], zuo1, zuo2;
bool b1, b2, b3, b4;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	for (unsigned char i=0;i<14;i++) {
		temp[i] = std::getchar();
	}
	xiang1[0]=temp[0]; xiang1[1]=temp[1]; pai1[0]=temp[3];pai1[1]=temp[4];zuo1=temp[5];
	xiang2[0]=temp[7]; xiang2[1]=temp[8]; pai2[0]=temp[10];pai2[1]=temp[11];zuo2=temp[12];
	b1=xiang1[0]==xiang2[0]&&xiang1[1]==xiang2[1];
	b2=b1&&pai1[0]==pai2[0]&&pai1[1]==pai2[1];
	b3=b2&&((zuo1<='C'&&zuo2<='C')||(zuo1>'C'&&zuo2>'C'));
	b4=b3&&(zuo1-zuo2==-1||zuo1-zuo2==1);
	std::printf("%d%d%d%d", b1, b2, b3, b4);
	return 0;
}
