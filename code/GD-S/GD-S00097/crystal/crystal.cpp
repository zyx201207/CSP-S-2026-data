#include <iostream>
#include <cstdio>
//#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int gN = 0;
long long gM = 0;

long long gDataTab[5 * 100000 + 5] = {0};

void printDataTab() {
	printf("dataTab :: \n");
	int i;
	for(i = 0; i < gN; i++) {
		printf("%lld ", gDataTab[i]);
	}
	printf("\n \n");
}

void inputData() {
	int i;
	cin >> gN >> gM;
	//printf("n = %d m = %d \n", gN, gM);

	for(i = 0; i < gN; i++) {
		cin >> gDataTab[i];
	}
}

bool cmpDataTab(long long a, long long b) {
	return a < b;
}

int getBPos(long long x) {
	int i;
	int l = 0;
	int r = gN - 1;
	while(l < r) {
		int mid = (l + r) / 2;

		if(x > gDataTab[mid]) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}

	return l;
}

void sortDataTab() {
	sort(gDataTab, gDataTab + gN, cmpDataTab);
}

int findPos(long long x) {
	int i;
	int rst = 0;
	for(i = 0; i < gN; i++) {
		if(x <= gDataTab[i]) {
			rst = i;
			break;
		}
	}

	return rst;
}

int getNumber(long long x) {
	int rst = 0;
	//int curPos = findPos(x);
	int curPos = getBPos(x);

	//printf("test out %lld curPos = %d \n", x, curPos);

	int i;

	if(gDataTab[curPos] == x && curPos < gN - 1) {
		rst++;
		i = curPos + 1;
		while(gDataTab[i] <= x) {
			rst++;
			i++;
		}
	}

	if(curPos == gN - 1) {
		rst++;
	}

	i = curPos - 1;
	long long countM = 0;
	while(i >= 0) {
		if(countM + (x - gDataTab[i]) <= gM) {
			countM += (x - gDataTab[i]);
			rst++;
		} else {
			break;
		}
		i--;
	}

	//cout << rst << endl;

	return rst;

}

void runSolve() {
	long long i;
	long long smallNumber = gDataTab[0];
	long long maxNumber = gDataTab[gN - 1];
	//cout << smallNumber << " " << maxNumber;

	int rst = -1;

	for(i = smallNumber; i <= maxNumber; i++) {

		int tempA = getNumber(i);
		rst = max(rst, tempA);

	}

	cout << rst;
}

int main(int argc, char** argv) {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	inputData();
	//printDataTab();

	sortDataTab();
	//printDataTab();
	//printf("test %d %d \n", findPos(-5), gDataTab[findPos(-5)]);

	//printf("test %d %d \n", getBPos(-5), gDataTab[getBPos(-5)]);

	runSolve();




	return 0;
}
